#!/usr/bin/env python
from autogen.autogen import autogen

project = "KDSoap"
version = "1.3.98"
subprojects = ["KDSoapClient", "KDSoapServer"]
prefixed = False

autogen(project, version, subprojects, prefixed, policyVersion = 2)
