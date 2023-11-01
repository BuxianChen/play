import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Permutation {
    public static void main(String[] args) {
        int k = Integer.parseInt(args[0]);
        if (k == 0)
            return;
        int i = 0;
        RandomizedQueue<String> rq = new RandomizedQueue<String>();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (i < k)
                rq.enqueue(item);
            else if (StdRandom.uniform(i + 1) < k) {
                rq.dequeue();
                rq.enqueue(item);
            }
            i++;
        }
        // StdOut.println(rq.size());
        for (String str : rq) {
            StdOut.println(str);
        }
    }
}
