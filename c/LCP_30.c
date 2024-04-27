void swap(int *nums, int i, int j) {
    int x = nums[i];
    nums[i] = nums[j];
    nums[j] = x;
}

void down(int *nums, int size, int i) {
    for (int k = 2 * i + 1; k < size; k = 2 * k + 1) {
        // 父节点 (k - 1) / 2，左子节点 k，右子节点 k + 1
        if (k + 1 < size && nums[k] > nums[k + 1]) {
            k++;
        }
        if (nums[k] > nums[(k - 1) / 2]) {
            break;
        }
        swap(nums, k, (k - 1) / 2);
    }
}

void push(int *nums, int size, int x) {
    nums[size] = x;
    for (int i = size; i > 0 && nums[(i - 1) / 2] > nums[i]; i = (i - 1) / 2) {
        swap(nums, i, (i - 1) / 2);
    }
}

int pop(int *nums, int size) {
    swap(nums, 0, size - 1);
    down(nums, size - 1, 0);
    return nums[size - 1];
}

int magicTower(int *nums, int numsSize){
    int *q = (int *)malloc(sizeof(int) * numsSize);
    int qn = 0;
    int ans = 0;
    long long hp = 1, delay = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num < 0) {
            push(q, qn, num);
            qn++;
        }
        hp += num;
        if (hp <= 0) {
            ans++;
            delay += q[0];
            hp -= pop(q, qn);
            qn--;
        }
    }
    free(q);
    return hp + delay <= 0 ? -1 : ans;
}