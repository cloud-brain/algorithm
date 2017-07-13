def clear_letter(x):
    x = list(x)
    pre_char = x[0]
    count = 0
    i = 0
    while i < len(x):
        pre_char = x[i]
        i = i + 1
        if i >= len(x):
            break
        if(x[i] == pre_char):
            end_flag = i + 1
            while(end_flag < len(x) and x[end_flag] == pre_char):
                end_flag = end_flag + 1
            del x[(i - 1):end_flag]
            count = count + end_flag - i + 1
            i = i - 1
    return count


def max_clear_letter(x):
    max_clear = 0
    for i in range(len(x)):
        y = x[:i] + 'A' + x[i:]
        max_clear = max(max_clear, clear_letter(y))
        y = x[:i] + 'B' + x[i:]
        max_clear = max(max_clear, clear_letter(y))
        y = x[:i] + 'C' + x[i:]
        max_clear = max(max_clear, clear_letter(y))
    return max_clear


n = input()
for i in range(n - 1):
    x = input()
    print(max_clear_letter(x))
