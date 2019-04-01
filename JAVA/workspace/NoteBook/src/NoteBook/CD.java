package NoteBook;

public class CD extends Item{
		
	public CD(String title, String artist, int numofTracks, int playingTime, String comment) 
	{
		super(title, artist, numofTracks, playingTime, false, comment);
	}
	
	public static void main(String[] args) {
		CD cd = new CD("abc", "hanray", 5, 60, "...");
		cd.print();
	}
}
