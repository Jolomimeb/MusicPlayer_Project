#include "Song.h" //Loads the Songs

//Name: Song - Default Constructor
//Precondition: None
//Postcondition: Creates a default song using "New Title", "New Artist", 0 , 0 and sets m_next = nullptr;
Song::Song() {
  m_title = "New Title";
  m_artist = "New Artist";
  m_year = 0;
  m_rank = 0;
  m_next = nullptr;
}

//Name: Song - Overloaded Constructor
//Precondition: Requires title, artist, year, and rank
//Postcondition: Creates a song based on passed parameters and sets m_next = nullptr;
Song::Song(string title, string artist, int year, int rank) {
  m_title = title;
  m_artist = artist;
  m_year = year;
  m_rank = rank;
  m_next = nullptr;
}

string Song::GetTitle() {
  // return title
  return m_title;
}

string Song::GetArtist() {
  // return artist
  return m_artist;
}

int Song::GetYear() {
  // return year
  return m_year;
}

int Song::GetRank() {
  // return rank (1-100 from that year)
  return m_rank;
}

void Song::SetTitle(string title) {
  // sets title
  m_title = title;
}
void Song::SetArtist(string artist) {
  //sets artist
  m_artist = artist;
}

void Song::SetYear(int year) {
  //sets year
  m_year = year;
}

void Song::SetRank(int rank) {
  //sets rank
  m_rank = rank;
}

// Linked List specific getters and setters
// Name: GetNext()
// Desc: Returns the pointer to the next song
// Preconditions: None (may return either song or nullptr)
// Postconditions: Returns m_next;
Song* Song::GetNext() {
  return m_next;
}

// Name: SetNext()
// Desc: Updates the pointer to a new target (either a song or nullptr)
// Preconditions: None
// Postconditions: Sets the next song
void Song::SetNext(Song* next) {
  m_next = next;
}
