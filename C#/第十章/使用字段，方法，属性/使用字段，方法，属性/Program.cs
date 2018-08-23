using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 使用字段_方法_属性
{
    class Program
    {
        static void Main(string[] args)
        {
            WriteLine("Creating object myObj...");
            MyClass myObj = new MyClass("My Object");//实例化
            WriteLine("myObj created.");
            for(int i=-1;i<=0;i++)
            {
                try
                {
                    WriteLine($"\nAttempting to assign {i} to myObj.Val...");
                    myObj.Val = i;
                    WriteLine($"Value {myObj.Val} assigned to myObj.Val");
                }
                catch (Exception e)//如果在try块中出现了异常，则执行catch块的内容
                {
                    WriteLine($"Exception {e.GetType().FullName} thrown.");
                    WriteLine($"Message:\n\"{e.Message}\"");
                }
            }
            WriteLine("\nOutputting myObj.ToString()...");
            WriteLine(myObj.ToString());
            WriteLine("myObj.ToString() output");

            WriteLine("\nmyDoubleIntProp = 5...");
            WriteLine($"Getting myDoubleIntprop of 5 is {myObj.myDoubleIntProp}");
            ReadKey();
        }
    }
}
