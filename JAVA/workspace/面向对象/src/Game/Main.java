package Game;

public class Main {
	//创建房间
	private Rooms outside = new Rooms("城堡外");
	private Rooms hall = new Rooms("大厅");
	private Rooms bedroom = new Rooms("卧室");
	private Rooms bookRoom = new Rooms("书房");
	private Rooms canteen = new Rooms("餐厅");
	private Rooms currentRoom = outside;
	
	//编辑地图
	public void EditMap()
	{
		outside.SetExit("north", hall);
		hall.SetExit("north", canteen);
		hall.SetExit("south", outside);
		hall.SetExit("east", bookRoom);
		canteen.SetExit("south", hall);
		bookRoom.SetExit("west", hall);
		bookRoom.SetExit("north", bedroom);
		bedroom.SetExit("south", bookRoom);
	}
	
	public void Start()
	{
		EditMap();
		System.out.println("欢迎来到我的城堡！");
		System.out.println("这是一个很无聊的游戏...");
		System.out.println("输入Help得到操作方法");
		ShowPosition();
	}
	
	public void ShowPosition()
	{
		System.out.println("你在" + currentRoom.GetName());
		System.out.print("出口有：" );
		System.out.println(currentRoom.RoomDesc());
	}
	
	//public void Play()
	
	public static void main(String[] args)
	{
		Main main = new Main();
		main.Start();
		
	}

}
