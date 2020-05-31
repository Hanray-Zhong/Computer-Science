package Chapter_19;

/**
 * �������ӿڣ����ڱ�����������ÿһ�����. ע���ⲻ��java.util.Iterator�ӿ�
 */
interface Iterator<T> {
    /**
     *  �Ƿ���Ԫ��
     * @return ���Ԫ�ػ�û�е����꣬����true;���򷵻�false
     */
    boolean hasNext();

    /**
     * ��ȡ��һ��Ԫ��
     * @return  ��һ��Ԫ��
     */
    T next();
}

/**
 * ���������
 * @param <T>
 */
class  ArrayIterator<T> implements Iterator<T>{
    private int pos = 0;
    private T[] a = null;

    public ArrayIterator(T[] array){
        a = array;
    }

    @Override
    public boolean hasNext() {
        return !(pos >= a.length);
    }

    @Override
    public T next() {
        if(hasNext()){
            T c = a[pos];
            pos ++;
            return c;
        }
        else
            return null;
    }
}

/**
 * �����࣬�ڲ���Object[]����Ԫ��
 */
class Container<T> {
    private T[] elements;
    private int elementsCount = 0;
    private int size = 0;

    public Container(int size){
        elements = (T[]) new Object[size];
        this.size = size;
    }

    public boolean add(T e){
        if(elementsCount < size){
            elements[elementsCount ++] = e;
            return true;
        }
        else{
            return  false;
        }
    }

    /**
     * ���������ĵ�����
     * @return
     */
    public Iterator<T> iterator(){
        return new ArrayIterator(elements);
    }
}
public class Test{
    public static void main(String[] args){
        Container<String> container = new Container<String>(6);
        container.add("12");
        container.add("34");
        container.add("56");
        container.add("78");
        container.add("9");
        Iterator<String> it = container.iterator();
        while (it.hasNext()){
            String s = (String)it.next();
            if( s != null)
                System.out.println(s);
        }
    }
}

