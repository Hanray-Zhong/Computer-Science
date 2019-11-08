using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 使用字段_方法_属性
{
    public class MyClass
    {
        public readonly string Name;//readonly表示只能在构造函数的过程中赋值，或由初始化赋值语句赋值
        private int intVal;//避免外部直接修改intVal的值
        public int Val
        {
            get { return intVal; }
            set
            {
                if (value >= 0 && value <= 10)
                    intVal = value;
                else
                    throw (new ArgumentOutOfRangeException("Val", value, 
                        "Val must be assigned a value between 0 and 10."));//返回异常
            }
        }
        public override string ToString() => "Name:" + Name + "\nVal:" + Val;
        //override表示重写基类方法（在此处ToString()为基类方法）
        private MyClass():this("Default Name") { }
        public MyClass(string newName)
        {
            Name = newName;
            intVal = 0;
        }
        private int myDoubleInt = 5;
        public int myDoubleIntProp => (myDoubleInt * 2);
    }
}
