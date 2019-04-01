package Demo;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import Demo.Student_Class;
import Demo.Student_Class.Sex;

public class Student_Controller {
	
	private static ArrayList<Student_Class> student_list = new ArrayList<Student_Class>();
	private static Scanner sc = new Scanner(System.in);

	private static int order = 0;
	
	public static void main(String[] args) throws IOException {
		
		int choice;
		System.out.println("-------------------------------------------------------");
		System.out.println("Please input a number to choose the function:\n"
				+ "1 - Add information of a new student.\n"
				+ "2 - Delete information of a student.\n"
				+ "3 - Get information by inputting a student's name.\n"
				+ "4 - Adjust information by inputting a student's name.\n"
				+ "0 - Exit!\n"
				+ "-------------------------------------------------------\n"
				+ "Your choice:");
		choice = sc.nextInt();
		sc.nextLine();
		while(choice != 0) {
			switch(choice) {
			case 1:	AddNewStudent();
					break;
			case 2:	DeleteStudentInfo();
					break;
			case 3: FindInfo();
					break;
			case 4:	AdjustInfo();
					break;
			default:System.out.println("Please input the current number!!!\n");
					break;
			}
			System.out.println("-------------------------------------------------------");
			System.out.println("Please input a number to choose the function:\n"
					+ "1 - Add information of a new student.\n"
					+ "2 - Delete information of a student.\n"
					+ "3 - Get information by inputting a student's name\n"
					+ "4 - Adjust information by inputting a student's name\n"
					+ "0 - Exit!\n"
					+ "-------------------------------------------------------\n"
					+ "Your choice:");
			choice = sc.nextInt();
			sc.nextLine();
		}
		
		System.out.println("Thank you for using!");
		
	}
	
	private static void AddNewStudent() {
		Student_Class newStudent = new Student_Class();
		System.out.println("\nbasic information:-------------------------\n");
		newStudent.Add_Basic_info();

		System.out.println("\nfamily information:------------------------\n");
		newStudent.Add_Family_Info();

		System.out.println("\ngrades:------------------------------------\n");
		newStudent.Add_Grades();

		System.out.println("\nother information:-------------------------\n");
		newStudent.Add_Other_info();

		student_list.add(newStudent);
		student_list.set(order, newStudent);
		order++;
	}

	private static void DeleteStudentInfo(){
		int student_ID = FindStudent();
		if(student_ID == -1){
			return;
		}
		student_list.remove(student_ID);
		System.out.println("Delete successfully!");
	}

	private static void FindInfo(){
		int student_ID = FindStudent();
		if(student_ID == -1){
			return;
		}
		GetInfo(student_list.get(student_ID));
	}


	private static void GetInfo(Student_Class student){
		System.out.println("\n------------------------Basic------------------------");
		System.out.println("name: " + student.name);
		System.out.println("age: " + student.age);
		System.out.println("Citizen_ID: " + student.Citizen_ID);
		System.out.println("Student_ID: " + student.Student_ID);
		System.out.println("sex: " + student.sex.toString());
		System.out.println("nationality: " + student.nationality);
		System.out.println("address: " + student.address);
		System.out.println("email_address: " + student.email_address);
		System.out.println("\n------------------------Family-----------------------");
		System.out.println("Father_name: " + student.family_information.Father_name);
		System.out.println("Mother_name: " + student.family_information.Mother_name);
		System.out.println("Mail_code: " + student.family_information.Mail_code);
		System.out.println("Father_tel: " + student.family_information.Father_tel);
		System.out.println("Mother_tel: " + student.family_information.Mother_tel);
		System.out.println("Family_tel: " + student.family_information.Family_tel);
		System.out.println("Father_occupation: " + student.family_information.Father_occupation);
		System.out.println("Mother_occupation: " + student.family_information.Mother_occupation);
		System.out.println("\n------------------------Grade------------------------");
		System.out.println("Chinese grade: " + student.grades.Chinese);
		System.out.println("Math grade: " + student.grades.Math);
		System.out.println("English grade: " + student.grades.English);
		System.out.println("Physics grade: " + student.grades.Physics);
		System.out.println("Chemistry grade: " + student.grades.Chemistry);
		System.out.println("Biology grade: " + student.grades.Biology);
		System.out.println("Geography grade: " + student.grades.Geography);
		System.out.println("History grade: " + student.grades.History);
		System.out.println("Politics grade: " + student.grades.Politics);
		System.out.println("\n------------------------Other------------------------");
		System.out.println("height: " + student.height);
		System.out.println("weight: " + student.weight);
		System.out.println("have_Physical_ability: " + student.have_Physical_ability);
		System.out.println("have_Psychological_ability: " + student.have_Psychological_ability);
		System.out.println("military_service: " + student.military_service);
	}

	private static void AdjustInfo(){
		int student_ID = FindStudent();
		if(student_ID == -1){
			return;
		}
		Student_Class currentStudent = student_list.get(student_ID);
		int Info_ID;
		System.out.println("-------------------------------------------------------");
		System.out.println("Please input the information you want to adjust: \n"
		+ "1 - Basic Information\n"
		+ "2 - Family Information\n"
		+ "3 - Grades\n"
		+ "4 - Other Information\n"
		+ "Your Choice: ");
		Info_ID = sc.nextInt();
		sc.nextLine();
		switch(Info_ID){
			case 1:	System.out.println("-------------------------------------------------------");
					currentStudent.Add_Basic_info();
					break;
			case 2: System.out.println("-------------------------------------------------------");
					currentStudent.Add_Family_Info();
					break;
			case 3: System.out.println("-------------------------------------------------------");
					currentStudent.Add_Grades();
					break;
			case 4: System.out.println("-------------------------------------------------------");
					currentStudent.Add_Other_info();
					break;
			default:System.out.println("Please input the current number!!!\n");
					break;
		}
	}

	private static int FindStudent(){
		System.out.println("Please input the name:");
		String name = sc.nextLine();
		int i = 0;
		if(student_list.size() == 0){
			System.out.println("The List is empty!!");
			return -1;
		}
		while(!student_list.get(i).name.equals(name)){
			i++;
			if(i == student_list.size()){
				System.out.println("Dno't found the student.");
				return -1;
			}
		}
		return i;
	}
}
