def is_triangular(num):
    # Check if a number is a triangular number
    n = (8 * num + 1) ** 0.5
    return n.is_integer() and (n - 1) % 2 == 0

def calculate_cost(weights, N, K):
    from collections import deque

    queue = deque(weights)
    count = 0
    last_box = None
    same_box_count = 0

    while same_box_count < K:
        current_cycle = list(queue)[:N]
        while len(current_cycle) > 1:
            if current_cycle[0] < current_cycle[1]:
                queue.append(queue.popleft())
            else:
                queue.append(queue.popleft())
                current_cycle.pop(0)
            current_cycle.pop(0)
        last_box = current_cycle[0]
        queue.append(queue.popleft())
        if queue[-1] == last_box:
            same_box_count += 1
        else:
            same_box_count = 0

    total_cost = sum(weight for weight in weights if not is_triangular(weight))
    return total_cost

# Input
weights = list(map(int, input().split()))
N, K = map(int, input().split())

# Calculate and print the cost
print(calculate_cost(weights, N, K))
