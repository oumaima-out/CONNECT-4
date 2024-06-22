void surface(){
    //fond
    fond= SDL_LoadBMP("fond.bmp");
    fond_menu= SDL_LoadBMP("fond_menu.bmp");
    //jetons jaune et rouge, vide et noir
    jaune = SDL_LoadBMP("jaune.bmp");
    SDL_SetColorKey(jaune, SDL_SRCCOLORKEY, SDL_MapRGB(jaune->format, 0, 0, 0));
    rouge = SDL_LoadBMP("rouge.bmp");
    SDL_SetColorKey(rouge, SDL_SRCCOLORKEY, SDL_MapRGB(rouge->format, 0, 0, 0));
    noir = SDL_LoadBMP("noir.bmp");
    SDL_SetColorKey(noir, SDL_SRCCOLORKEY, SDL_MapRGB(noir->format, 0, 0, 0));
    vide = SDL_LoadBMP("noir.bmp");
    SDL_SetColorKey(vide, SDL_SRCCOLORKEY, SDL_MapRGB(vide->format, 0, 0, 0));
}


//LIBERE LESPACE
void freesurface(){
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(fond);
    SDL_FreeSurface(rouge);
    SDL_FreeSurface(jaune);
    SDL_FreeSurface(noir);
    SDL_FreeSurface(vide);
    SDL_FreeSurface(texte);
}
