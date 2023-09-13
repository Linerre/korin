Inductive day : Type :=
 | monday
 | tuesday
 | wednesday
 | thursday
 | friday
 | saturday
 | sunday.

(** A function on days *)

Definition next_weekday (d:day) : day :=
  match d with
  | monday    => tuesday
  | tuesday   => wednesday
  | wednesday => thursday
  | thursday  => friday
  | friday    => monday
  | saturday  => monday
  | sunday    => monday
  end.

(** Simplification: *)

Compute (next_weekday friday).
(* ==> monday : day *)

Compute (next_weekday (next_weekday saturday)).

(** Second, we can record what we _expect_ the result to be in the
    form of a Coq example: *)
(* ==> tuesday : day *) (* assert_eq! in Rust *)

Example test_next_weekday :
  (next_weekday (next_weekday saturday)) = tuesday.

(** We can then present a _proof script_ giving evidence for
    the claim: *)

Proof. simpl. reflexivity. Qed.
