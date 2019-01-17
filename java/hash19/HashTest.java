package hash19;

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

public class HashTest {


    public static void main(String[] args) {
//        System.out.println(hash("another"));;
        linkedHashMap();
    }

    static int hash(Object key) {
        int h = key.hashCode();
        return (h ^ (h >>> 16)) & (12 -1); //capicity 表示散列表的大小
    }

    /**
     *
     */
    static void linkedHashMap(){
        // 10 是初始大小，0.75 是装载因子，true 是表示按照访问时间排序
        HashMap<Integer, Integer> m = new LinkedHashMap<>(3, 0.75f, true);
        m.put(3, 11);
        m.put(1, 12);
        m.put(5, 23);
        m.put(2, 22);

        m.put(3, 26);
        m.get(5);

        for (Map.Entry e : m.entrySet()) {
            System.out.println(e.getKey());
        }
    }




}
