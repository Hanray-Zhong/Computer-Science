using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace 嵌套类
{
    public class ClassA
    {
        private int state = -1;
        public int State
        {
            get
            {
                return state;
            }
        }//将ClassA的值设置为只读
        public class ClassB
        {
            public void SetPrivateState(ClassA target, int newState)
            {
                target.state = newState;//访问了private
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            ClassA ObejectA = new ClassA();
            WriteLine(ObejectA.State);
            ClassA.ClassB ObejectB = new ClassA.ClassB();
            ObejectB.SetPrivateState(ObejectA, 999);//成功在类以外修改了private值
            WriteLine(ObejectA.State);
            ReadKey();
        }
    }
}
