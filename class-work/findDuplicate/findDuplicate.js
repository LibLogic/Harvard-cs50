function findDuplicate(arr) {
    var seen = {};
    for (let i = 0; i < arr.length; i++){
        if (seen[arr[i]]) {
            return arr[i];
        }
        else {
            seen[arr[i]] = true;
        }
    }
console.log(seen, "hello");
}

console.log(findDuplicate([1, 2, 4, 5, 3, 7, 5, 22, 23, 27, 77]));