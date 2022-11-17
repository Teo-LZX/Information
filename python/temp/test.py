import argparse

parser = argparse.ArgumentParser(description='Process some integers.')
# parser.add_argument('integers', metavar='N', type=int, nargs='+',
#                     help='an integer for the accumulator')
# parser.add_argument('--sum', dest='accumulate', action='store_const',
#                     const=sum, default=max,
#                     help='sum the integers (default: find the max)')
parser.add_argument("--seed", type=int, default=5, help="random seed for initialization")
parser.add_argument('--model_name', default="ernie-3.0-base-zh", help="Select model to train, defaults to ernie-3.0-medium-zh.")
args = parser.parse_args()

print(args.seed)
print(args.model_name)