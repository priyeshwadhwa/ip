package IterateOverCube;

public class IterateOverCube {
    public int[] findCell(final int N, long index) {
        for (int sum = 0;; ++sum) {
            long count = countSum(3, N, sum);
            if (index < count) {
                for (int x = 0; x < N; ++x) {
                    count = countSum(2, N, sum - x);
                    if (index < count) {
                        for (int y = 0; y < N; ++y) {
                            count = countSum(1, N, sum - x - y);
                            if (index < count) {
                                if (index != 0)
                                    throw new RuntimeException();
                                return new int[] { x, y, sum - x - y };
                            } else {
                                index -= count;
                            }
                        }
                    } else {
                        index -= count;
                    }
                }
            } else {
                index -= count;
            }
        }
    }

    private long countSum(final int count, final int N, final int sum) {
        if (sum < 0)
            return 0;
        long res = 0;
        long ways = 1;
        for (int bigger = 0; bigger <= count; ++bigger) {
            final int rem = sum - bigger * N;
            if (rem < 0)
                break;
            long prod = 1;
            for (int i = 0; i < (count - 1); ++i) {
                prod = prod * (rem + count - 1 - i) / (i + 1);
            }
            res += ways * prod;
            ways = ways * (count - bigger) / (bigger + 1);
            ways = -ways;
        }
        return res;
    }

    public static void main(final String[] args) {

        IterateOverCube s = new IterateOverCube();
        s.findCell(3,9);
    } 
}

