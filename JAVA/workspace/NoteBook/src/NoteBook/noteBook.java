package NoteBook;

import java.util.ArrayList;

public class noteBook {
	
	private ArrayList<String> notes = new ArrayList<String>();
	
	public void add(String content)
	{
		notes.add(content);
	}
	
	public void add(String content, int order)
	{
		notes.add(order, content);
	}
	
	public int GetSize()
	{
		return notes.size();
	}
	
	public String GetNote(int number)
	{
		return notes.get(number);
	}
	
	public void RemoveNote(int number)
	{
		notes.remove(number);
	}
	
	public String[] list()
	{
		String[] a = new String[notes.size()];
//		for(int i = 0; i < notes.size(); i++)
//		{
//			a[i] = notes.get(i);
//		}
		notes.toArray(a);
		return a;
	}
	
	public static void main(String[] args) 
	{
		noteBook note = new noteBook();
		note.add("hanray");
		note.add("ÖÓ×Óè¡");
		
		System.out.println(note.GetSize());

	}

}
