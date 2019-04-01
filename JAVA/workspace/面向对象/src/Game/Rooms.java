package Game;

import java.util.HashMap;

public class Rooms{
	
	
	public Rooms(String name)
	{
		this.name = name;
	}
	
	//���������洢�����������Ϣ
	private HashMap<String, Rooms> exits = new HashMap<String, Rooms>();
	private String name;
	
	//��������Ϣ�洢��������
	public Rooms SetExit(String direction, Rooms room)
	{
		return exits.put(direction, room);
	}
	
	//�õ���������Щ����
	public String RoomDesc()
	{
		StringBuffer sb = new StringBuffer();
		for(String dir : exits.keySet())
		{
			sb.append(dir + " ");
		}
		return sb.toString();
	}
	
	//����Ӧ�ĳ����ҵ���Ӧ�ķ���
	public Rooms GetExit(String direction)
	{
		return exits.get(direction);
	}
	
	public String GetName()
	{
		return name;
	}
	
}
