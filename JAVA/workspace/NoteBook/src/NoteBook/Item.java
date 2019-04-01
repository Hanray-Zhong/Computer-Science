package NoteBook;

public class Item {
	
	private String title;
	private String artist;
	private int numofTracks;
	private int playingTime;
	private boolean getIt;
	private String comment;
	
	public Item(String title, String artist, int numofTracks, int playingTime, 
			boolean getIt, String comment) {
		super();
		this.title = title;
		this.artist = artist;
		this.numofTracks = numofTracks;
		this.playingTime = playingTime;
		this.getIt = getIt;
		this.comment = comment;
	}
	
	public void print()
	{
		System.out.println(title + ":" + artist);
	}
	
}
