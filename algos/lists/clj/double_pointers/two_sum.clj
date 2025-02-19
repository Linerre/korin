(ns double-pointers.two-sum)

;;; Leetcode 167
;;; https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

(defn two-sum [nums target]
  (loop [[l r] [0 (dec (count nums))]]
    (let [s (+ (nums l) (nums r))]
      (cond
        (= s target) [(inc l) (inc r)]
        (> s target) (recur [l (dec r)])
        (< s target) (recur [(inc l) r])))))

(comment (two-sum [2,7,11,15] 9))
;; [1 2]

(comment (two-sum [2,3,4] 6))
;; [1,3]

(comment (two-sum [-1, 0] -1))
;; [1,2]
