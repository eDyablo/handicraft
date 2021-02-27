def solve(riddle):
    answer = list(riddle)
    size = len(answer)
    if size > 0:
        if answer[0] == '?':
            answer[0] = 'b'
        for i in range(1, size):
            prev = ord(answer[i-1])
            if answer[i-1] == answer[i]:
                answer[i-1] = chr(prev - 1)
            elif answer[i] == '?':
                answer[i] = chr(prev + 2) if prev + 2 <= ord('z') else 'a'
    return ''.join(answer)
