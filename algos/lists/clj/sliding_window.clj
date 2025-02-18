(ns sliding-window)

;;; Leetcode 209
;;; https://leetcode.com/problems/minimum-size-subarray-sum/description/

;;; Input: target = 7, nums = [2,3,1,2,4,3]
;;; Output: 2
;;; Explanation: The subarray [4,3] has the minimal length under the problem constraint.
;;;
;;; Example 2:
;;;
;;; Input: target = 4, nums = [1,4,4]
;;; Output: 1
;;;
;;; Example 3:
;;;
;;; Input: target = 11, nums = [1,1,1,1,1,1,1,1]
;;; Output: 0

(defn min-sub-array-len [target nums]
  (let [n (count nums)]
    (loop [right 0
           left  0
           sum   0
           ans   (inc n)]
      (if (>= right n)
        ;; done
        (if (<= ans n) ans 0)
        ;; narrow the sliding window from left to right by droping the leftmost val
        (let [[a s l] (loop [l left
                             s (+ sum (nth nums right))
                             a ans]
                        (if (>= s target)
                          (recur (inc l)
                                 (- s (nth nums l))
                                 (min ans (- (inc right) l)))
                          [a, s, l]))]
          (recur (inc right) l s (min ans a)))))))

(comment
  (min-sub-array-len 7 [2 3 1 2 4 3]))

(comment
  (min-sub-array-len 4 [1 4 4]))

(comment
  (min-sub-array-len 11 [1,1,1,1,1,1,1,1]))

;; more of clojure style
(defn min-sub-array-len2 [target nums]
  (->> (range (count nums))
       (reduce
        (fn [[left sum ans] right]
          (let [new-sum (+ sum (nth nums right))
                [new-left new-sum new-ans]
                (loop [l left, s new-sum, a ans]
                  (if (>= s target)
                    (recur (inc l)
                           (- s (nth nums l))
                           (min a (- (inc right) l)))
                    [l s a]))]
            [new-left new-sum new-ans]))
        [0 0 Integer/MAX_VALUE])
       last
       (#(if (= Integer/MAX_VALUE %) 0 %))))

(comment
  (min-sub-array-len2 7 [2 3 1 2 4 3]))
