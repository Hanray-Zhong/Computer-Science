package Chapter_11_to_13;

public class Faculty extends Person {
    private String email;
    private String title;
    private int facultyId;

    public Faculty() { }
    public Faculty(String name, int age, int facultyId, String title, String email)
    {
        this.name = name;
        this.age = age;
        this.facultyId = facultyId;
        this.title = title;
        this.email = email;
    }

    public int getFacultyId()
    {
        return facultyId;
    }
    public void setFacultyId(int facultyId)
    {
        this.facultyId = facultyId;
    }
    public String getEmail()
    {
        return email;
    }
    public void setEmail(String email)
    {
        this.email = email;
    }
    public String getTitle()
    {
        return title;
    }
    public void setTitle(String title)
    {
        this.title = title;
    }
    @Override
    public String toString()
    {
        String info = "name: " + name + ", age: " + age + ", facultyId: " + facultyId + ", title: " + title + ", email: " + email + "\n";
        return info;
    }
    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
    @Override
    public boolean equals(Object obj)
    {
        if (!(obj instanceof Faculty))
            return false;
            
            Faculty faculty = (Faculty)obj;
        if (faculty.name.equals(this.name) && faculty.age == this.age && faculty.facultyId == this.facultyId && faculty.title.equals(this.title) && faculty.email.equals(this.email))
            return true;
        else
            return false;
    }
}
