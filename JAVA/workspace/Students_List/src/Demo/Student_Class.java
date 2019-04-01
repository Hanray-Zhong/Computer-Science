package Demo;

import java.util.Scanner;

public class Student_Class {
	
	public enum Sex{
		man,
		woman,
		Unkonwn,
	}
	
	private static Scanner sc = new Scanner(System.in);


	public String name;

	public int age;
	public String Citizen_ID;
	public String Student_ID;
	public Sex sex;
	public String nationality;
	public String address;
	public String email_address;
	public String telephone_number;
	
	public Family_info family_information;
	
	public Grades grades;
	
	public double height;
	public double weight;
	
	public boolean have_Physical_ability;
	public boolean have_Psychological_ability;
	public boolean military_service;

	public void Add_Basic_info(){
		sc.nextLine();
		System.out.println("name:");
		this.name = sc.nextLine();
		System.out.println("age:");
		this.age = sc.nextInt();
		sc.nextLine();
		System.out.println("Citizen_ID:");
		this.Citizen_ID = sc.nextLine();
		System.out.println("Student_ID:");
		this.Student_ID = sc.nextLine();
		System.out.println("sex: (0 - man, 1 - woman)");
		int sexID = sc.nextInt();
		sc.nextLine();
		switch(sexID){
			case 0:	this.sex = Sex.man;
					break;
			case 1: this.sex = Sex.woman;
					break;
			default:this.sex = Sex.Unkonwn;
					break;
		}
		System.out.println("nationality:");
		this.nationality = sc.nextLine();
		System.out.println("address:");
		this.address = sc.nextLine();
		System.out.println("email address:");
		this.email_address = sc.nextLine();
		System.out.println("telephone number:");
		this.telephone_number = sc.nextLine();
	}

	public void Add_Other_info(){
		System.out.println("height:");
		this.height = sc.nextDouble();
		sc.nextLine();
		System.out.println("weight:");
		this.weight = sc.nextDouble();
		sc.nextLine();

		System.out.println("Have Physical Ability:(true/false)");
		this.have_Physical_ability = sc.nextBoolean();
		System.out.println("Have Psychological Ability:(true/false)");
		this.have_Psychological_ability = sc.nextBoolean();
		System.out.println("Military Service:(true/false)");
		this.military_service = sc.nextBoolean();
	}

	public void Add_Family_Info()
	{
		Family_info newInfo = new Family_info();

		sc.nextLine();
		System.out.println("Father_name:");
		newInfo.Father_name = sc.nextLine();
		System.out.println("Mother_name:");
		newInfo.Mother_name = sc.nextLine();

		System.out.println("Mail_code:");
		newInfo.Mail_code = sc.nextLine();
		System.out.println("Father_tel:");
		newInfo.Father_tel = sc.nextLine();
		System.out.println("Mother_tel:");
		newInfo.Mother_tel = sc.nextLine();
		System.out.println("Family_tel:");
		newInfo.Family_tel = sc.nextLine();
		System.out.println("Father_occupation:");
		newInfo.Father_occupation = sc.nextLine();
		System.out.println("Mother_occupation:");
		newInfo.Mother_occupation = sc.nextLine();

		this.family_information = newInfo;
	}

	public void Add_Grades()
	{
		Grades newGrades = new Grades();

		System.out.print("Chinese: ");
		newGrades.Chinese = sc.nextInt();
		sc.nextLine();
		System.out.print("Math: ");
		newGrades.Math = sc.nextInt();
		sc.nextLine();
		System.out.print("English: ");
		newGrades.English = sc.nextInt();
		sc.nextLine();
		System.out.print("Physics: ");
		newGrades.Physics = sc.nextInt();
		sc.nextLine();
		System.out.print("Chemistry: ");
		newGrades.Chemistry = sc.nextInt();
		sc.nextLine();
		System.out.print("Biology: ");
		newGrades.Biology = sc.nextInt();
		sc.nextLine();
		System.out.print("Geography: ");
		newGrades.Geography = sc.nextInt();
		sc.nextLine();
		System.out.print("History: ");
		newGrades.History = sc.nextInt();
		sc.nextLine();
		System.out.print("Politics: ");
		newGrades.Politics = sc.nextInt();
		sc.nextLine();

		this.grades = newGrades;
	}
	
}
