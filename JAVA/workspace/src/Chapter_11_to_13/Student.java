package Chapter_11_to_13;

public class Student extends Person {
    private String classNo;
    private String department;
    private int studentId;

    public Student() { }
    public Student(String name, int age, int studentId, String department, String classNo)
    {
        this.name = name;
        this.age = age;
        this.studentId = studentId;
        this.department = department;
        this.classNo = classNo;
    }

    
    public int getStudentId()
    {
        return studentId;
    }
    public void setStudentId(int studentId)
    {
        this.studentId = studentId;
    }
    public String getDepartment()
    {
        return department;
    }
    public void setDepartment(String department)
    {
        this.department = department;
    }
    public String getClassNo()
    {
        return classNo;
    }
    public void setClassNo(String classNo)
    {
        this.classNo = classNo;
    }
    @Override
    public String toString()
    {
        String info = "name: " + name + ", age: " + age + ", studentId: " + studentId + ", department: " + department + ", classNo: " + classNo + "\n";
        return info;
    }
    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
    @Override
    public boolean equals(Object obj)
    {
        if (!(obj instanceof Student))
            return false;
            
        Student student = (Student)obj;
        if (student.name.equals(this.name) && student.age == this.age && student.studentId == this.studentId && student.department.equals(this.department) && student.classNo.equals(this.classNo))
            return true;
        else
            return false;
    }
}
