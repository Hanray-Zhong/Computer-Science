using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 字符串处理
{
    class Program
    {
        static void Main(string[] args)
        {
            string myString;
            myString = ReadLine();
            WriteLine($"you input {myString.Length} charracter.");
            char[] myChar = myString.ToCharArray();            //将string变量转换为char型的数组
            foreach(char charracter in myChar)
            {
                WriteLine($"{charracter}");
            }
            WriteLine("将字符串换成全部大写/小写并删除首尾空格：");
            myString = myString.Trim();                                  //删除首尾的空格
            WriteLine($"{myString.ToUpper()}\n"+$"{myString.ToLower()}");//转换大写小写
            char[] trim_char = { 'a' };
            myString = myString.Trim(trim_char);                      //删除前导/后导字符a，变量必须是数组
                                                                      //还包括TrimStart(),TrimEnd(),可以删除前导或后导
            WriteLine($"{myString}");
            ReadKey();
        }
    }
}
