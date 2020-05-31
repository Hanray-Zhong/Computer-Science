package Chapter_11_to_13;

import java.util.ArrayList;
import java.util.List;

public class Course extends Object implements Cloneable {
    private String courseName;
    private List<Person> students = new ArrayList<Person>();
    private Person teacher;

    public Course(String courseName, Person teacher)
    {
        this.courseName = courseName;
        this.teacher = teacher;
    }

    public void register(Person s)
    {
        if (!students.contains(s))
        {
            students.add(s);
        }
    }
    public String getCourseName()
    {
        return courseName;
    }
    public List<Person> getStudents()
    {
        return students;
    }
    public Person getTeacher()
    {
        return teacher;
    }
    public void unregister(Person s)
    {
        if (students.contains(s))
        {
            students.remove(s);
        }
    }
    public int getNumberOfStudents()
    {
        return students.size();
    }
    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
    @Override
    public String toString()
    {
        StringBuffer result = new StringBuffer();

        result.append("Course Name: ");
        result.append(courseName);
        result.append("\nTeacher Info: ");
        result.append(teacher.toString());
        result.append("\nStudent List: \n");
        for (Person student : students) {
            result.append("\t");
            result.append(student.toString());
            result.append("\n");
        }
        result.append("Totally: ");
        result.append(getNumberOfStudents());
        result.append(".\n");

        String output = result.toString();
        return output;
    }
}
