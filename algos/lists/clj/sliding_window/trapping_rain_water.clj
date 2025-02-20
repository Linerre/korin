(ns sliding-window.trapping-rain-water)

;;; Leetcode 42
;;; https://leetcode.com/problems/trapping-rain-water/

;;; using `loop`
;;; time: O(n)
;;; space: O(n)
(defn trapping-rain-water [heights]
  (let [[pre-c & lrest] heights
        [suf-c & rrest] (rseq heights)]
    (loop [pre-maxs [pre-c]
           [new-pre-c & new-pre-rest] lrest
           suf-maxs (conj '() suf-c)
           [new-suf-c & new-suf-rest] rrest]
      (if (seq new-pre-rest)
        (recur (conj pre-maxs (max new-pre-c (peek pre-maxs)))
               new-pre-rest
               (conj suf-maxs (max new-suf-c (first suf-maxs)))
               new-suf-rest)
        (reduce + (apply map #(- (min %1 %2) %3)
                         (conj []
                               (conj pre-maxs (max new-pre-c (peek pre-maxs)))
                               (vec (conj suf-maxs (max new-suf-c (peek suf-maxs))))
                               heights)))))))

(assert (= 6 (trapping-rain-water [0,1,0,2,1,0,1,3,2,1,2,1])))
;; => 6

(assert (= 9 (trapping-rain-water [4,2,0,3,2,5])))
;; => 9


;;; without `loop`
;;; time: O(n)
;;; space: O(n)
(defn trapping-rain-water2 [heights]
  (let [pre-maxs (reductions max heights)
        sub-maxs (reverse (reductions max (rseq heights)))
        target (conj [] pre-maxs sub-maxs heights)]
    (reduce + (apply map #(- (min %1 %2) %3) target))))

(comment (trapping-rain-water2 [0,1,0,2,1,0,1,3,2,1,2,1]))
;; => 6

(comment (trapping-rain-water2 [4,2,0,3,2,5]))
;; => 9

;;; Use double pointers
;;; time: O(n)
;;; space: O(1)
(defn trapping-rain-water3 [heights]
  (loop [[l r] [0 (dec (count heights))]
         pre-max (max 0 (heights l))
         suf-max (max 0 (heights r))
         ans 0]
    (if (< l r)                         ; when (= r l) there is no space for water
      (if (< pre-max suf-max)
        (recur [(inc l), r]
               (max pre-max (heights (inc l)))
               (max suf-max (heights r))
               (+ ans (- pre-max (heights l))))
        (recur [l, (dec r)]
               (max pre-max (heights l))
               (max suf-max (heights (dec r)))
               (+ ans (- suf-max (heights r)))))

      ans)))

(comment (trapping-rain-water3 [0,1,0,2,1,0,1,3,2,1,2,1]))
;; => 6

(comment (trapping-rain-water3 [4,2,0,3,2,5]))
;; => 9
