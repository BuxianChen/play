import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;


// 16 + 8(a) + 4(n) + 4(padding) + (16 + 4 + 4 + 8N) = 56 + 4N??
public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] a;
    private int n;

    // construct an empty randomized queue
    public RandomizedQueue() {
        a = (Item[]) new Object[2];
    }

    // is the randomized queue empty?
    public boolean isEmpty() {
        return n == 0;
    }

    // return the number of items on the randomized queue
    public int size() {
        return n;
    }

    private void resize(int size) {
        assert size >= n;
        Item[] temp = (Item[]) new Object[size];
        for (int i = 0; i < n; i++)
            temp[i] = a[i];
        a = temp;
    }

    // add the item
    public void enqueue(Item item) {
        if (item == null)
            throw new IllegalArgumentException();
        if (n == a.length)
            resize(2 * n);
        //int i = StdRandom.uniform(++n);
        //a[n - 1] = a[i];
        //a[i] = item;
        a[n++] = item;
    }

    // remove and return a random item
    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException();
        int j = StdRandom.uniform(n);
        Item temp = a[j];
        a[j] = a[n - 1];
        a[n - 1] = null;
        --n;
        if (n > 0 && n == a.length / 4) resize(a.length / 2);
        return temp;
    }

    // return a random item (but do not remove it)
    public Item sample() {
        if (isEmpty()) throw new NoSuchElementException();
        return a[StdRandom.uniform(n)];
    }

    // return an independent iterator over items in random order
    public Iterator<Item> iterator() {
        return new RandomizedQueueIterator();
    }

    private class RandomizedQueueIterator implements Iterator<Item> {
        private Item[] shuffleA;
        private int current = 0;

        public RandomizedQueueIterator() {
            shuffleA = (Item[]) new Object[n];
            if (n > 0)
                shuffleA[0] = a[0];
            for (int i = 1; i < n; i++) {
                int j = StdRandom.uniform(i + 1);
                shuffleA[i] = shuffleA[j];
                shuffleA[j] = a[i];
            }
        }

        public boolean hasNext() {
            return current != n;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            return shuffleA[current++];
        }
    }

    // unit testing (required)
    public static void main(String[] args) {
        RandomizedQueue<Integer> rq = new RandomizedQueue<Integer>();
        rq.enqueue(1);
        rq.enqueue(2);
        rq.enqueue(3);
        rq.dequeue();
        rq.isEmpty();
        rq.sample();
        rq.size();
        for (Integer integer : rq) {
            StdOut.println(integer);
        }
    }
}
