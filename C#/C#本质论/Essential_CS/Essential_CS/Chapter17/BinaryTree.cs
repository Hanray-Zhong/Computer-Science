using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Essential_CS.Chapter17
{
    public class BinaryTree<T> : IEnumerable<T>
    {
        public BinaryTree (T value) {
            Value = value;
        }

        #region IEnumrable<T>
        public IEnumerator<T> GetEnumerator() {
            // root
            yield return Value; 

            // 开始遍历子节点
            foreach (BinaryTree<T> tree in SubItems) {
                if (tree != null) {
                    // 对子节点的递归遍历
                    foreach(T item in tree) {
                        yield return item;
                    }
                }
            }
        }

        IEnumerator IEnumerable.GetEnumerator() {
            return GetEnumerator();
        }
        #endregion

        public T Value { get; set; }
        public Pair<BinaryTree<T>> SubItems { get; set; }
    }

    public struct Pair<T>: IEnumerable<T>
    {
        public Pair(T first, T second) : this() {
            First = first;
            Second = second;
        }
        public T First { get; }
        public T Second { get; }

        #region
        public IEnumerator<T> GetEnumerator() {
            // 循环迭代两次
            yield return First;
            yield return Second;
        }
        #endregion

        #region IEnumerable Mambers
        IEnumerator IEnumerable.GetEnumerator() {
            return GetEnumerator();
        }
        #endregion
    }
}
