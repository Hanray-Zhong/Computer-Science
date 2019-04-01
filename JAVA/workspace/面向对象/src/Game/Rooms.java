package Game;

import java.util.HashMap;

public class Rooms{
	
	
	public Rooms(String name)
	{
		this.name = name;
	}
	
	//创建容器存储房间的所有信息
	private HashMap<String, Rooms> exits = new HashMap<String, Rooms>();
	private String name;
	
	//将房间信息存储到容器中
	public Rooms SetExit(String direction, Rooms room)
	{
		return exits.put(direction, room);
	}
	
	//得到房间有哪些出口
	public String RoomDesc()
	{
		StringBuffer sb = new StringBuffer();
		for(String dir : exits.keySet())
		{
			sb.append(dir + " ");
		}
		return sb.toString();
	}
	
	//由相应的出口找到对应的房间
	public Rooms GetExit(String direction)
	{
		return exits.get(direction);
	}
	
	public String GetName()
	{
		return name;
	}
	
}
