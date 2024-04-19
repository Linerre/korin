f x = x * x

data Icecream = Chocolate | Vanilla deriving (Show, Eq, Ord)

-- data SixSidedDie = S1 | S2 | S3 | S4 | S5 | S6 deriving (Show)
-- deriving Show only


-- Implement `Show` for SixSidedDie
-- Similar to Rust's impl trait for user-type
data SixSidedDie = S1 | S2 | S3 | S4 | S5 | S6
instance Show SixSidedDie where
  show S1  = "one"
  show S2  = "two"
  show S3  = "three"
  show S4  = "four"
  show S5  = "five"
  show S6  = "six"
