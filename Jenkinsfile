#!/usr/bin/env groovy

node {
    if (env.BRANCH_NAME.startsWith('PR')) {
        return;
    }

    def image
    def entrypoint = "-d";
    def currentStage;
    try {
        stage('Cleanup and Checkout') {
            sh("echo Branch_name:${env.BRANCH_NAME}");
            cleanWs();
            checkout([
                $class: 'GitSCM',
                branches: [[name: "${env.BRANCH_NAME}"]],
                doGenerateSubmoduleConfigurations: false,
                extensions: [],
                submoduleCfg: [],
                userRemoteConfigs: [[credentialsId: 'Yorisoft', url: 'https://github.com/Yorisoft/cpp-labs']]
            ])
        }

        stage('Build Image') {
            image = docker.build('cpp-labs');
        }

        parallel(
            currentStage = 'Building BankAccounts config=deposit-fees-test'
            stage(currentStage) {
                image.inside(entrypoint) {
                    sh("chmod +x 284/Group_Project/BankAccounts/scripts/test/deposit-fees/deposit-fees-build.test.sh");
                    sh('284/Group_Project/BankAccounts/scripts/test/deposit-fees/deposit-fees-build.test.sh');
                    echo('Done building BankAccounts project files.. config=deposit-fees-test');
                } 
            } 

            currentStage = 'Building BankAccounts config=saving-withdrawal-fees-test'
            stage(currentStage) {
                image.inside(entrypoint) {
                    sh("chmod +x 284/Group_Project/BankAccounts/scripts/test/saving-withdrawal-fees/saving-withdrawal-fees-build.test.sh");
                    sh('284/Group_Project/BankAccounts/scripts/test/saving-withdrawal-fees/saving-withdrawal-fees-build.test.sh');
                    echo('Done building BankAccounts project files.. config=saving-withdrawal-fees');
                }
            }
        )

        parallel(
            currentStage = 'Running BankAccounts config=deposit-fees-test'
            stage(currentStage) {
                image.inside(entrypoint) {
                    sh("chmod +x 284/Group_Project/BankAccounts/scripts/test/deposit-fees/deposit-fees-run.test.sh");
                    sh('284/Group_Project/BankAccounts/scripts/test/deposit-fees/deposit-fees-run.test.sh');
                    echo('Done running BankAccounts project.. config=deposit-fees-test');
                }
            }

            currentStage = 'Running BankAccounts config=saving-withdrawal-fees-test'
            stage(currentStage) {
                image.inside(entrypoint) {
                    sh("chmod +x 284/Group_Project/BankAccounts/scripts/test/saving-withdrawal-fees/saving-withdrawal-fees-run.test.sh");
                    sh('284/Group_Project/BankAccounts/scripts/test/saving-withdrawal-fees/saving-withdrawal-fees-run.test.sh');
                    echo('Done running BankAccounts project.. config=saving-withdrawal-fees');
                }
            }
        )
    }
    catch (e) {
        currentBuild.result = 'FAILURE';
        throw e
    } finally {
        stage('Create Archive'){
            archiveArtifacts allowEmptyArchive: true, artifacts: '284/Group_Project/BankAccounts/bin/**', fingerprint: true;
        }

        stage('cleanup'){
            cleanWs();
            sh('docker system prune -a -f');
        }
    }
}