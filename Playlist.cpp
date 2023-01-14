#include "Playlist.h"
#include "Song.h"

// Name: Playlist() - Default Constructor
// Desc - Creates a new empty playlist
// Preconditions - None
// Postconditions - Sets everything to either nullptr or 0
Playlist::Playlist() {
  m_head = nullptr; //Head of the playlist
  m_tail = nullptr; //End of the playlist
  m_size = 0;
}

// Name: ~Playlist - Destructor
// Desc - Removes all of the songs from the playlist
// Preconditions - Playlist must have songs
// Postconditions - Playlist will be empty and m_head and m_tail will be nullptr. Size will be 0
Playlist::~Playlist() {

  Song* my_curr = m_head;
  while (m_head != nullptr) { //Iterates through and removes each node
    m_head = m_head -> GetNext(); //moves curr to next node
    delete my_curr; //delete m_head;
    my_curr = m_head; //sets m_head to curr
  }
  //Resets all of the static linked list pointers
  m_head = nullptr; //Sets the pointer to point at nothing
  m_tail = nullptr; //Sets the pointer to point at nothing
  m_size = 0; //Sets the size of the linked list to 0
}

// Name: AddSong(string, string, int, int)
// Desc - Dynamically allocates new song using title, artist, year, and rank
// Preconditions - Playlist allocated
// Postconditions - New song inserted in end of list
void Playlist::AddSong(string title , string artist, int year, int rank) {
  //Adds song to the playlist
  Song* songs = new Song( title,  artist, year, rank);
  if (m_head == nullptr) {
    m_head = songs;
    m_tail = songs;
  }
  else {
    m_tail->SetNext(songs);
    m_tail = songs;
  }
  m_size++;
}

// Name: GetPlaylistDetails()
// Desc - Returns a song object from a specific location
// Preconditions - Playlist populated
// Postconditions - Returns the data (does not output it)
Song* Playlist::GetPlaylistDetails(int location) {

  Song* curr = m_head;
  for (int i = 0; i < location; i++) {
    curr = curr -> GetNext();
  }
  return curr;
}

// Name: Size
// Desc - Returns the m_size
// Preconditions - Playlist starts at size 0
// Postconditions - Returns the size
int Playlist::Size() {
  return m_size;
}

// Name: PlayAt
// Desc - Passed the song that is to be played from the playlist
//       "Plays" a song by removing it from the playlist at a specific location
// Recommendations - Code this function last (dead last)
// Preconditions - Playlist has been populated
// Hint: Do not forget about removing from the front, middle, or end of the list
//       Could also remove the only node
// Postconditions - Playlist is reduced in size by one based on which song is played
void Playlist::PlayAt(int location) {

  //Special case if list empty
  if (m_size == 0) {
    cout << "No Songs to play" << endl;
    return;
  }
  //if only one song in linked list
  if (m_size == 1) {
    delete m_head;
    m_head = nullptr;
    m_tail = nullptr;
    m_size--;
    return;
  }

  //deleting first song in linkedlist
  if (location == 0) {
    Song* temp = m_head;
    if (m_head == nullptr) {
      return;
    }
    m_head = m_head->GetNext();
    delete temp;
    m_size--;

  }

  //deleting last song in linkedlist
  else if (location == (m_size - 1)) {
    Song* my_curr = m_head; //Create a temp node and set it to the head node
    while (my_curr->GetNext() != m_tail) { //Iterate until temp is the next to last node
      my_curr = my_curr->GetNext();
    }
    delete m_tail; // Delete the last node
    my_curr = nullptr; //Null temp's next
    m_tail = my_curr; //Reset the tail node
    m_size--; //Decrement the size
  }
  //deleting from middle in linked list
  else {
    Song* curr = m_head;
    Song* prev = m_head;
    int counter = 0;
    while (curr != nullptr) {
      if (counter == location) {
	prev->SetNext(curr->GetNext());
	delete curr;
	m_size--;
	return;
      }
      prev = curr;
      curr = curr->GetNext();
      counter++;
    }
    m_size--;
  }


}
