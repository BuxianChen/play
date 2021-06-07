class Insertion {
	// 不能被实例化的类可以按这种写法来写
	private Insertion() {}
	public static void sort(Comparable[] a) {
		int n = a.length;
		for (int i = 1; i < n; ++i) {
			int j = i;
			while(j > 0) {
				if (less(a[j], a[j-1])) {
					exch(a, j, j - 1);
					--j;
				}
				else
					break;
			}
			assert isSorted(a, 0, i + 1);
		}
	}
	private static void exch(Comparable[] a, int i, int j) {
		Comparable temp = a[i]; a[i] = a[j]; a[j] = temp;
	}
	private static boolean less(Comparable x, Comparable y) {
		return x.compareTo(y) < 0;
	}
	private static boolean eq(Comparable x, Comparable y) {
		return x.compareTo(y) == 0;
	}
	// a[low, high) is sorted
	private static boolean isSorted(Comparable[] a, int low, int high) {
		for (int i = low; i < high - 1; ++i)
			if (less(a[i+1], a[i])) return false;
		return true;
	}
}