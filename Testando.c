



while(running)
{
    while(SDL_PollEvent(&event)) // check to see if an event has happened
    {
        switch(event.type)
        {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONDOWN: // if the event is mouse click
                if(event.mouse.x >= 100)  // check if it is in the desired area
                {
                    //do something    
                }
        }
    }
}
