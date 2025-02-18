(ns sliding-window.container-with-most-water)

;;; Leetcode 11
;;; https://leetcode.com/problems/container-with-most-water/description/

;;; Example 1:
;;; Input: height = [1,8,6,2,5,4,8,3,7]
;;; Output: 49
;;; Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
;;;
;;; Example 2:
;;;
;;; Input: height = [1,1]
;;; Output: 1

(defn container-with-most-water [bars]
  (let [n (count bars)
        ans (loop [l   0
                   r   (- n 1)
                   ans 0
                   lh  (nth bars l)
                   rh  (nth bars r)]
              (if (< l r)
                (if (< lh rh)
                  (recur (inc l)
                         r
                         (max ans (* (min lh rh) (- r l)))
                         (nth bars (inc l))
                         rh)
                  (recur l
                         (dec r)
                         (max ans (* (min lh rh) (- r l)))
                         lh
                         (nth bars (dec r))))
                ans))]
    ans))

(comment
  (container-with-most-water [1,8,6,2,5,4,8,3,7]))
;; 49

(comment
  (container-with-most-water [1,1]))
;; 1

(comment
  (container-with-most-water [1,10,8,2,9,5]))
;; 27

;; Improved version by Claude
(defn container-with-most-water2 [heights]
  (loop [[l r] [0 (dec (count heights))]
         max-area 0]
    (if (< l r)
      (let [height (min (heights l) (heights r))
            width  (- r l)
            area   (* height width)]
        (if (< (heights l) (heights r))
          (recur [(inc l) r] (max max-area area))
          (recur [l (dec r)] (max max-area area))))
      max-area)))

(comment
  (container-with-most-water2 [1,8,6,2,5,4,8,3,7]))
