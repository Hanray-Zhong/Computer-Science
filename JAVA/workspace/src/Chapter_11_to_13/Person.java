package Chapter_11_to_13;

public class Person extends Object implements Cloneable {
    protected String name;
    protected int age;

    Person() { }
    Person(String name, int age)
    {
        this.name = name;
        this.age = age;
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
    @Override
    public boolean equals(Object obj)
    {
        if (!(obj instanceof Person))
            return false;

        Person person = (Person)obj;
        if (person.name.equals(this.name) && person.age == this.age)
            return true;
        else
            return false;
    }
    public int getAge()
    {
        return this.age;
    }
    public String getName()
    {
        return this.name;
    }
    public void setAge(int age)
    {
        this.age = age;
    }
    public void setName(String name)
    {
        this.name = name;
    }
    @Override
    public String toString()
    {
        String info = "name: " + name + ", age: " + age + "\n";
        return info;
    }
}
