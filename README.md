# c-structure-alignment

Example of C structure alignment.

## Compilation

```sh
clang -Weverything main.c -o output
```

## Not aligned members

Considering that memory is access by chrunks of 4 bytes,
then the following structure members are not aligned
(`two` is not aligned), so the compiler automatically
aligns it by adding a padding.

```c
struct NotAligned {
    char one; // 1 byte
    // PADDING required: 3 bytes
    int two; // 4 bytes
};
``` 

## Aligned members

The following structure members are aligned as they take less than one chrunk.

```c
struct Aligned {
    char one; // 1 byte
    char two; // 1 byte
    // 2 bytes left that could be used for others bytes or shorts
};
```

The following structure members are aligned as well:

```c
struct OtherAligned {
    int one; // 4 bytes
    char two, three, four, five; // 4 bytes
}; // takes exactly two chrunks (two double words), no padding necessary
```

## Order matters

Not optimized order:

```c
struct NotOptimized {
    char one; // 1 byte
    // PADDING of 3 bytes
    int two; // 4 bytes
    char three; // 1 byte
    // PADDING of 3 bytes
}; // we lose 6 bytes
```

Optimized order:

```c
struct Optimized {
    char one; // 1 byte
    char three; // 1 byte
    // PADDING of 2 bytes
    int two; // 4 bytes
};
```

## Disable automatic padding

Using `__attribute__((packed))` removes automatic padding and alignment.

```c
struct NotAligned {
    char one;
    int two;
} __attribute__((packed));
```

As the attribute `two` is now on two chrunks (two different double-words in memory),
it needs at least two operations to access its data (double-word calculation + offset).
In case of padding, it would have only requires one operation (double-word calculation).
