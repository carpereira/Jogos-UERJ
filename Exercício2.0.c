let didDrag = false;
let didHandlePointerDown = false;
let dragOrigin;
let origPos;

const rectContains = ({ top, right, bottom, left }, x, y) =>
  left <= x && x <= right && top <= y && y <= bottom;

(function handleFrame() {
  if (mouse.buttons[0].pressed) {
    const { clientX, clientY } = mouse.location;
    const draggableRect = draggable.getBoundingClientRect();

    if (
      !didHandlePointerDown &&
      rectContains(draggableRect, clientX, clientY)
    ) {
      // Handle pointerdown
      dragOrigin = { x: clientX, y: clientY };
      origPos = {
        left: draggableRect.left,
        top: draggableRect.top,
      };
      didDrag = false;
    }

    // Ensure that we only act on pointerdown action in the
    // first frame that we detect that the button is pressed.
    didHandlePointerDown = true;

    if (
      dragOrigin &&
      (clientX !== dragOrigin.x || clientY !== dragOrigin.y)
    ) {
      // Handle pointermove
      didDrag = true;
      const deltaX = clientX - dragOrigin.x;
      const deltaY = clientY - dragOrigin.y;
      draggable.style.left = `${origPos.left + deltaX}px`;
      draggable.style.top = `${origPos.top + deltaY}px`;
      setStatus("dragging...");
    }
  } else if (dragOrigin) {
    // Handle pointerup
    dragOrigin = undefined;
    if (didDrag) {
      setStatus("Dropped!");
    } else {
      setStatus("Clicked!");
    }
  } else {
    didHandlePointerDown = false;
  }

  if (dragOrigin && keyboard.keys["Escape"].pressed) {
    // Handle keypress
    dragOrigin = undefined;
    draggable.style.left = `${origPos.left}px`;
    draggable.style.top = `${origPos.top}px`;
    setStatus("Cancelled!");
  }

  requestAnimationFrame(handleFrame);
})();
