import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;
import java.util.NoSuchElementException;

// linked list
// 16+8+8+4+4+(16+8+8+8)*n=40+40n

public class Deque<Item> implements Iterable<Item> {

    private Node<Item> first, last;
    private int n;


    private static class Node<Item> {
        private Item item;
        private Node<Item> next;
        private Node<Item> prev;
    }

    public Deque() {
    }

    public boolean isEmpty() {
        return n == 0;
    }

    public int size() {
        return n;
    }

    public void addFirst(Item item) {
        if (item == null)
            throw new IllegalArgumentException();
        if (isEmpty()) {
            first = new Node<Item>();
            first.item = item;
            last = first;
        }
        else {
            Node<Item> oldFirst = first;
            first = new Node<Item>();
            first.item = item;
            first.next = oldFirst;
            oldFirst.prev = first;
        }
        ++n;
    }

    public void addLast(Item item) {
        if (item == null)
            throw new IllegalArgumentException();
        if (isEmpty())
            addFirst(item);
        else {
            Node<Item> oldLast = last;
            last = new Node<Item>();
            last.item = item;
            last.prev = oldLast;
            oldLast.next = last;
            ++n;
        }
    }

    public Item removeFirst() {
        if (isEmpty())
            throw new NoSuchElementException();
        Item res = first.item;
        if (size() == 1) {
            first = null;
            last = null;
        }
        else {
            first = first.next;
            first.prev = null;
        }
        --n;
        return res;
    }

    public Item removeLast() {
        if (isEmpty())
            throw new NoSuchElementException();
        Item res = last.item;
        if (size() == 1) {
            first = null;
            last = null;
        }
        else {
            last = last.prev;
            last.next = null;
        }
        --n;
        return res;
    }

    public Iterator<Item> iterator() {
        return new DequeIterator();
    }

    private class DequeIterator implements Iterator<Item> {
        private Node<Item> current = first;

        public boolean hasNext() {
            return current != null;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

    public static void main(String[] args) {
        Deque<Integer> dq = new Deque<Integer>();
        StdOut.println(dq.size());
        dq.addFirst(12);
        dq.addFirst(13);
        dq.addLast(1);
        for (Iterator<Integer> it = dq.iterator(); it.hasNext(); ) {
            int i = it.next();
            StdOut.println(i);
        }
        int a = dq.removeFirst();
        a = dq.removeLast();
        dq.addLast(3);
        dq.isEmpty();
        StdOut.println(dq.size());
        for (Iterator<Integer> it = dq.iterator(); it.hasNext(); ) {
            int i = it.next();
            StdOut.println(i);
        }
    }
}
