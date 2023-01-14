#include "MusicPlayer.h"

//Name: MusicPlayer - Default Constructor
//Precondition: None
//Postcondition: Dynamically creates a new MusicPlayer
MusicPlayer::MusicPlayer() {
  m_playList = new Playlist();

}

//Name: ~MusicPlayer - Destructor
//Precondition: None
//Postcondition: Destructs all songs in the catalog and all songs in the playlist
MusicPlayer::~MusicPlayer() {
  //loops through the catalog and deletes all songs
  for (unsigned int i = 0; i < m_songCatalog.size(); i++) {
    delete m_songCatalog.at(i);
  }
  delete m_playList;

}

//Name: LoadCatalog(string filename)
//Precondition: Requires filename
//Postcondition: Loads the file of songs into the m_songCatalog (as song objects) using the DELIMITER
void MusicPlayer::LoadCatalog(string filename) {
  string SongName;
  string ArtistName;
  string SongYear;
  string SongRank;

  ifstream myfile(FILE_NAME);

  //loads the file of songs and put its it in the songcatalog
  if (myfile.is_open()) {
    while (getline(myfile, SongName, DELIMITER) && getline(myfile, ArtistName, DELIMITER)){
      getline(myfile, SongYear, DELIMITER) && getline(myfile, SongRank);
      m_songCatalog.push_back(new Song(SongName, ArtistName, stoi(SongYear), stoi(SongRank)));
    }
    cout << "Songs Loaded: " << int(m_songCatalog.size()) << endl;
  }
  else {
    cout << "didn't open" << endl;
  }

  myfile.close();
}

//Name: MainMenu
//Precondition: None
//Postcondition: Manages the application and the menu. Calls until user chooses to quit.
void MusicPlayer::MainMenu() {
  int user_choice;
  do {
    do {
      cout << "What would you like to do? " << endl;
      cout << "1. Display Songs by Year" << endl;
      cout << "2. Add Song" << endl;
      cout << "3. Display Playlist" << endl;
      cout << "4. Play Song" << endl;
      cout << "5. Quit" << endl;
      cin >> user_choice;
    } while ((user_choice < 1) or (user_choice > 5));


    if (user_choice == 1) {
      DisplaySongs();
    }
    else if (user_choice == 2) {
      AddSong();
    }
    else if (user_choice == 3) {
      DisplayPlaylist();
    }
    else if (user_choice == 4) {
      PlaySong();
    }
    else if (user_choice == 5) {
      cout << "Thank you for using the UMBC Music Player. " << endl;
    }
  } while (user_choice != 5);
}

//Name: DisplaySongs
//Precondition: User enters year using constants above (2010-2021)
//Postcondition: Lists all songs (numbered) for that year by ranking
void MusicPlayer::DisplaySongs() {
  int song_year;
  do {
    cout << "What year would you like to display? (2010 - 2021) " << endl;
    cin >> song_year;
  } while ((song_year < LOW_YEAR) or (song_year > HIGH_YEAR));
  cout << "****** " << song_year << " ******" << endl;


  for (unsigned int i = 0; i < m_songCatalog.size(); i++) {

    if (m_songCatalog.at(i)->GetYear() == song_year) {
      cout << i + 1 << ". " << * m_songCatalog.at(i) << endl;
    }
  }
}

//Name: AddSong
//Precondition: m_songCatalog is populated and m_playList exists
//Postcondition: Displays the songs for a specific year. Adds a song to the m_playList by dynamically allocating a new song based on the song in the catalog
//               and inserting it in the end.
//               May have duplicate songs on a playlist.
//               If the user chooses 2010, the user does not have to choose something from 2010 but it does need to be valid (between 1 - 1200)
void MusicPlayer::AddSong() {
  int song_number = 0;

  DisplayPlaylist();
  cout << "Choose the songs you would like to add to the playlist. " << endl;

  DisplaySongs();
  do {
    cout << "Enter the number of the song you would like to add: " << endl;
    cin >> song_number;

  } while ((song_number < 1) or (song_number > int(m_songCatalog.size())));
  song_number = song_number - 1;

  m_playList->AddSong(m_songCatalog.at(song_number) -> GetTitle(), m_songCatalog.at(song_number)->GetArtist(), m_songCatalog.at(song_number)->GetYear(), m_songCatalog.at(song_number)->GetRank());

}

//Name: DisplayPlaylist
//Precondition: None (can be empty)
//Postcondition: Displays the playlist or tells the user it is empty
void MusicPlayer::DisplayPlaylist() {

  if (m_playList->Size() == 0) {
    cout << "***Current Playlist is empty***" << endl;
  }
  else {
    cout << "Your Playlist" << endl;
    for (int i = 0; i < m_playList->Size(); i++) {
      cout << i + 1 << ". " << * m_playList->GetPlaylistDetails(i) << endl;
    }
  }
}

//Name: PlaySong
//Precondition: Playlist should be populated
//Postcondition: Allows the user to choose a song from the playlist to play.
//               Removes chosen song from playlist after "played"
void MusicPlayer::PlaySong() {
  int play_number;

  DisplayPlaylist();

  do {

    cout << "which song would you like to play? " << endl;
    cin >> play_number;
  } while (((play_number < 1) or (play_number > m_playList->Size())) and (m_playList->Size() != 0));

  play_number = play_number - 1;

  if (m_playList->Size() == 0) {
    cout << "No songs in playlist" << endl;
  }
  else {
    cout << "Played: " << *m_playList->GetPlaylistDetails(play_number) << endl;
    m_playList->PlayAt(play_number);
  }

}
