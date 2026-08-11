# Bubble Sort Using File Handling in C

## 📌 Homework সম্পর্কে

এই Homework-এ আমাদেরকে **File Handling ব্যবহার করে একটি File থেকে Array-এর value input নিতে হবে**, এরপর সেই value-গুলোকে **Bubble Sort algorithm** ব্যবহার করে ascending order-এ সাজাতে হবে।

Sorting সম্পন্ন হওয়ার পর sorted value-গুলোকে একটি **অন্য File-এ save করতে হবে**।

### Homework-এর মূল কাজ

পুরো কাজটিকে ৩টি ধাপে ভাগ করা যায়:

1. একটি input file থেকে array-এর value নিতে হবে।
2. নেওয়া value-গুলোকে Bubble Sort ব্যবহার করে ছোট থেকে বড় ক্রমে সাজাতে হবে।
3. Sorted value-গুলো একটি নতুন output file-এ লিখতে হবে।

### Example

ধরা যাক, `unsorted_value.txt` file-এ আছে:

```text
50 20 80 10 40 90 30 70 60 100
```

Bubble Sort করার পর:

```text
10 20 30 40 50 60 70 80 90 100
```

এই sorted value-গুলো `sorted_value.txt` file-এ save হবে।

---

# 🛠️ Technologies Used

* **Language:** C
* **Algorithm:** Bubble Sort
* **Concepts:** Array, File Handling, Loop, Conditional Statement

---

# 📁 Files

```text
├── bubble_sort_file.c
├── unsorted_value.txt
├── sorted_value.txt
└── README.md
```

### `bubble_sort_file.c`

এটি মূল C program যেখানে file থেকে data নেওয়া, sorting করা এবং অন্য file-এ data save করার কাজ করা হয়েছে।

### `unsorted_value.txt`

এই file-এ unsorted array values রাখা হয়েছে। Program এই file থেকে values read করে।

### `sorted_value.txt`

Bubble Sort করার পর sorted values এই file-এ save করা হয়।

### `README.md`

এই file-এ homework-এর উদ্দেশ্য এবং program-এর explanation দেওয়া হয়েছে।

---

# 🔍 Code Explanation

## 1. Header File Include

```c
#include <stdio.h>
```

`stdio.h` ব্যবহার করা হয়েছে কারণ আমাদের program-এ:

* `printf()`
* `fscanf()`
* `fprintf()`
* `fopen()`
* `fclose()`

এর মতো function ব্যবহার করা হয়েছে।

---

## 2. Array এবং Variable তৈরি

```c
int n = 10, temp;
int arr[10];
```

এখানে:

* `n = 10` → আমাদের array-তে মোট ১০টি value থাকবে।
* `arr[10]` → ১০টি integer value রাখার জন্য array।
* `temp` → দুইটি value swap করার সময় temporary variable হিসেবে ব্যবহার করা হয়েছে।

---

# 📥 3. Input File Open করা

```c
FILE *myfile;
myfile = fopen("unsorted_value.txt", "r");
```

এখানে `FILE *myfile` দিয়ে একটি file pointer তৈরি করা হয়েছে।

তারপর:

```c
fopen("unsorted_value.txt", "r");
```

দিয়ে `unsorted_value.txt` file-টি **read mode (`"r"`)**-এ open করা হয়েছে।

অর্থাৎ, এই file থেকে আমরা data পড়ব।

---

# 📖 4. File থেকে Array Input নেওয়া

```c
for(int i = 0; i < n; i++){
    fscanf(myfile, "%d", &arr[i]);
}
```

এই loop-এর মাধ্যমে file থেকে একে একে ১০টি integer value পড়া হচ্ছে এবং array-তে রাখা হচ্ছে।

উদাহরণ:

```text
File:
50 20 80 10 40
```

তাহলে array হবে:

```text
arr[0] = 50
arr[1] = 20
arr[2] = 80
arr[3] = 10
arr[4] = 40
```

এভাবে সব value array-তে চলে আসবে।

---

# 🔒 5. Input File Close করা

```c
fclose(myfile);
```

File থেকে data পড়া শেষ হওয়ার পর file-টি close করা হয়েছে।

এটি ভালো practice, কারণ কাজ শেষ হলে file properly close করা উচিত।

---

# 🖥️ 6. Unsorted Value দেখানো  (Optional)

```c
printf("Unsorted value from file :\n");

for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
}
```

এই অংশটি array-তে থাকা original/unsorted value screen-এ দেখায়।

---

# 🔄 7. Bubble Sort

এটাই program-এর সবচেয়ে গুরুত্বপূর্ণ অংশ।

```c
for(int i = 1; i < n; i++){
    for(int j = 0; j < n-i; j++){

        if(arr[j] > arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }

    }
}
```

এখানে **Bubble Sort** ব্যবহার করা হয়েছে।

### কীভাবে কাজ করে?

প্রতিবার পাশাপাশি দুইটি value compare করা হয়:

```text
arr[j] > arr[j+1]
```

যদি বাম পাশের value বড় হয়, তাহলে তাদের মধ্যে swap করা হয়।

### Example

ধরা যাক:

```text
50 20 80 10
```

প্রথম comparison:

```text
50 > 20
```

তাই swap হবে:

```text
20 50 80 10
```

পরের comparison:

```text
50 > 80
```

False, তাই কোনো swap হবে না।

পরের comparison:

```text
80 > 10
```

True, তাই:

```text
20 50 10 80
```

এভাবে বারবার comparison এবং swapping করার মাধ্যমে সবচেয়ে বড় value ধীরে ধীরে array-এর শেষের দিকে চলে যায়।

এই কারণেই algorithm-টির নাম **Bubble Sort**।

---

# 🔁 8. Swap করার জন্য `temp`

```c
temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
```

এই তিনটি line দুইটি value swap করে।

যেমন:

```text
arr[j]   = 50
arr[j+1] = 20
```

প্রথমে:

```text
temp = 50
```

তারপর:

```text
arr[j] = 20
```

এবং শেষে:

```text
arr[j+1] = 50
```

ফলে:

```text
20 50
```

হয়ে যায়।

---

# 📊 9. Sorted Array দেখানো (Optional)

Sorting শেষ হওয়ার পর:

```c
printf("\nSorted value :\n");

for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
}
```

এর মাধ্যমে sorted array screen-এ দেখানো হয়েছে।

---

# 📤 10. Output File Open করা

```c
myfile = fopen("sorted_value.txt", "w");
```

এবার `sorted_value.txt` file-টি **write mode (`"w"`)**-এ open করা হয়েছে।

`"w"` ব্যবহার করার অর্থ হলো file-এ নতুন data লেখা হবে।

---

# 💾 11. Sorted Value File-এ লেখা

```c
for(int i = 0; i < n; i++){
    fprintf(myfile, "%d ", arr[i]);
}
```

এই loop-এর মাধ্যমে sorted array-এর প্রতিটি value `sorted_value.txt` file-এ লেখা হচ্ছে।

যেমন sorted array:

```text
10 20 30 40 50 60 70 80 90 100
```

তাহলে output file-এও থাকবে:

```text
10 20 30 40 50 60 70 80 90 100
```

---

# 🔒 12. Output File Close করা

```c
fclose(myfile);
```

Sorted values file-এ লেখা শেষ হওয়ার পর file-টি close করা হয়েছে।

---

# ▶️ Program Flow

পুরো program-এর কাজটি সহজভাবে:

```text
unsorted_value.txt
        ↓
   Read Values
        ↓
      Array
        ↓
   Bubble Sort
        ↓
 Sorted Array
        ↓
sorted_value.txt
```

অর্থাৎ:

**File → Array → Bubble Sort → Output File**

---

# 🧪 Sample Input

`unsorted_value.txt`

```text
50 20 80 10 40 90 30 70 60 100
```

# 🖥️ Sample Output

```text
Unsorted value from file :
50 20 80 10 40 90 30 70 60 100

Sorted value :
10 20 30 40 50 60 70 80 90 100
```

# 📄 Output File

`sorted_value.txt`

```text
10 20 30 40 50 60 70 80 90 100
```

---

# 🎯 Concepts Practiced

এই Homework-এর মাধ্যমে নিচের বিষয়গুলো practice করা হয়েছে:

* Array
* `for` loop
* File Handling
* `FILE` pointer
* `fopen()`
* `fscanf()`
* `fprintf()`
* `fclose()`
* Bubble Sort
* Swapping
* Reading data from a file
* Writing data to a file

---

## 👨‍💻 Author
I hope it will helpful for you. ❌❌ But Please do not copy my code exactly. ❌❌  !! Thank You !! 
~ Srabon
