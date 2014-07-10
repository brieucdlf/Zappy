from optparse import OptionParser
from define import *

def parse_argument(argv):
    parser = OptionParser()
    parser.add_option("-a", "--address", dest="ip", default=DEFAULT_IP,
                      help="Server ip address")
    parser.add_option("-p", "--port", dest="port", default=DEFAULT_PORT,
                      help="Server port")
    argument = parser.parse_args()
    return argument[0].__dict__
