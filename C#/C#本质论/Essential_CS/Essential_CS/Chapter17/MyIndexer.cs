using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Essential_CS.Chapter17
{
    public class MyIndexer
    {
        public enum PairItem
        {
            First,
            Second,
        }

        interface IPari<T>
        {
            T First { get; }
            T Second { get; }

            T this[PairItem index] { get; }
        }

        public struct Pair<T> : IPari<T>
        {
            public T First { get; }
            public T Second { get; }
            public Pair(T first, T second) {
                First = first;
                Second = second;
            }

            public T this[PairItem index] {
                get {
                    switch (index) {
                        case PairItem.First:
                            return First;
                        case PairItem.Second:
                            return Second;
                        default:
                            throw new NotImplementedException($"The enum {index.ToString()} has not been implemented");
                    }
                }
            }
        }
    }

    
}
