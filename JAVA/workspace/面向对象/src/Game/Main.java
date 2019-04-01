package Game;

public class Main {
	//��������
	private Rooms outside = new Rooms("�Ǳ���");
	private Rooms hall = new Rooms("����");
	private Rooms bedroom = new Rooms("����");
	private Rooms bookRoom = new Rooms("�鷿");
	private Rooms canteen = new Rooms("����");
	private Rooms currentRoom = outside;
	
	//�༭��ͼ
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
		System.out.println("��ӭ�����ҵĳǱ���");
		System.out.println("����һ�������ĵ���Ϸ...");
		System.out.println("����Help�õ���������");
		ShowPosition();
	}
	
	public void ShowPosition()
	{
		System.out.println("����" + currentRoom.GetName());
		System.out.print("�����У�" );
		System.out.println(currentRoom.RoomDesc());
	}
	
	//public void Play()
	
	public static void main(String[] args)
	{
		Main main = new Main();
		main.Start();
		
	}

}
