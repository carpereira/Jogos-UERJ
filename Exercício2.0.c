const draggable = document.getElementById("myObject");
const setStatus = (str) =>
  (document.getElementById("status").textContent = str);

const events = new abro.EventSource(draggable);
const windowEvents = new abro.EventSource(window);

abro.loop(async () => {
  // Control will block on this line until pointerdown happens.
  const downEvent = await events.pointerdown; 👈 1️⃣
  downEvent.target.setPointerCapture(downEvent.pointerId);

  const { left, top } = draggable.getBoundingClientRect();
  const origPos = { left, top };

  let didDrag = false;

  // `abro.or` starts multiple fibers, and completes as soon as *one*
  // of them completes (the others are terminated).
  await abro.or( 👈 2️⃣
    async function handleDrag() {
      // An infinite loop? Abro will terminate this fiber when either
      // `handlePointerUp` or `handleEscape` is done.
      while (true) { 👈 3️⃣
        const { clientX, clientY } = await events.pointermove;
        didDrag = true;
        const deltaX = clientX - downEvent.x;
        const deltaY = clientY - downEvent.y;
        draggable.style.left = `${origPos.left + deltaX}px`;
        draggable.style.top = `${origPos.top + deltaY}px`;
        setStatus("dragging...");
      }
    },
    async function handlePointerUp() {
      await events.pointerup;
      if (didDrag) {
        setStatus("Dropped!");
      } else {
        setStatus("Clicked!");
      }
    },
    async function handleEscape() {
      let key;
      while (key !== "Escape") {
        ({ key } = await windowEvents.keydown);
      }
      draggable.style.left = `${origPos.left}px`;
      draggable.style.top = `${origPos.top}px`;
      setStatus("Cancelled!");
    }
  );
});


