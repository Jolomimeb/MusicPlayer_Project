
#include <iostream>
#include "MusicPlayer.h" //Loads the MusicPlayer
#include "Playlist.h" //Loads the Playlist
#include "Song.h" //Loads the Songs

//Takes in an argument when you call this program
int main() {
    string musicFile = "proj3_music.txt";
    cout << "Welcome to Jolomi's Music Player" << endl;
    
    MusicPlayer* myMusic = new MusicPlayer(); //Dynamically allocates a new music player
    myMusic->LoadCatalog(musicFile); //Loads the catalog
    myMusic->MainMenu(); //Calls MainMenu
    delete myMusic; //Deallocates the music player
    return 0;
}
