package NoteBook;

public class DVD extends Item{
	public DVD(String title, String artist, int numofTracks, int playingTime, String comment) 
	{
		super(title, artist, numofTracks, playingTime, false, comment);
	}
	
	public static void main(String[] args) {
		DVD dvd = new DVD("def", "ÖÓ×Óè¡", 5, 60, "...");
		dvd.print();
	}
}
