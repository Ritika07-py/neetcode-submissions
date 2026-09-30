class Solution {
    fun minEatingSpeed(piles: IntArray, h: Int): Int {
        var speed = 1
        while (true) {
            var totalTime = 0L
            for (pile in piles) {
                totalTime += Math.ceil(pile.toDouble() / speed).toLong()
            }

            if (totalTime <= h) {
                return speed
            }
            speed += 1
        }
        return speed
    }
}