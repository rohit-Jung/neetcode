## approaches

### arrays and hashing

- when it comes to duplicate, you can use `set`
- for `count` related problem you can have a `hashmap`
- a unique way i found is anagram was to utilize the `charCode/ASCII code` 
  and maintain a count of it to compare two strings

- `twoSum` like problem be careful what's being stored and what's being retrieved.
   also what do you want to check in the map for - current thing ? 

- `topKFrequent` - frequency is similar use hashmap count em 
   for the returning of `k elems`, we use bucket sort but inverse em 

- `sum except self` - postfix and prefix - remember to update the postfix and prefix with original 
   array of nums ? then in postfix you keep multiplying back 

- `valid sudoku` - for 3/3 grid you need to divide the whole board into 3/3, by diving the index by 3
   store the `index -> elems in that (cols, rows, square)` and check for duplicates. since duplicate `set`

- `palindrome` - take care of `lowercase` and `alphanum`, two pointer or the sorted and reverse method
