package NoteBook;

import java.util.ArrayList;

public class Database {
	/*----------------------------*/
	public ArrayList<Item> CD_DVD_list = new ArrayList<Item>();
	public void Add(Item item)
	{
		CD_DVD_list.add(item);
	}
	public void list()
	{
		for(Item item : CD_DVD_list)
		{
			item.print();
		}
	}

	public static void main(String[] args) {
		Database db = new Database();
		
		db.Add(new CD("abc", "hanray", 5, 60, "..."));
		db.Add(new DVD("def", "ÖÓ×Óè¡", 5, 60, "..."));
		
		db.list();
	}
}
