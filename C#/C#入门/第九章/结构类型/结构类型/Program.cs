using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 结构类型
{
    class MyClass
    {
        public int val;
    }
    struct MyStruct
    {
        public int val;
    }
    class Program
    {
        static void Main(string[] args)
        {
            MyClass objectA = new MyClass();
            MyClass objectB = objectA;
            objectA.val = 10;
            objectB.val = 20;
            MyStruct structA = new MyStruct();
            MyStruct structB = structA;
            structA.val = 30;
            structB.val = 40;
            WriteLine($"objectA = {objectA.val}");
            WriteLine($"objectB = {objectB.val}");
            WriteLine($"structA = {structA.val}");
            WriteLine($"structB = {structB.val}");
            ReadKey();
        }
    }
}
