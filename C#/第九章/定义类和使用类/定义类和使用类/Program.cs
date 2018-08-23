using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 定义类和使用类
{
    public abstract class mybase { }
    internal class myClass : mybase { }
    public interface ImybaseInterface { }
    internal interface ImybaseInterface2 { }
    internal interface ImyInterface : ImybaseInterface, ImybaseInterface2 { }
    internal sealed class myComplexClass : myClass, ImyInterface { }
    class Program
    {
        static void Main(string[] args)
        {
            myComplexClass myObj = new myComplexClass();
            WriteLine(myObj.ToString());
            ReadKey();
        }
    }
}
