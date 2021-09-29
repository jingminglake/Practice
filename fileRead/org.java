package com.paypal.risk.paymentevaluation.model;

import java.util.Objects;
import java.util.ArrayList;
import com.fasterxml.jackson.annotation.*;
import java.util.Objects;
import javax.validation.constraints.*;
import javax.validation.Valid;

@javax.annotation.Generated(value = "com.paypal.ppaas.swagger.codegen.PPaaSJAXRSSwaggerCodegen", date = "2018-12-04T21:59:28.670-08:00")
@JsonInclude(value = JsonInclude.Include.NON_NULL)
@JsonIgnoreProperties(ignoreUnknown = true)
public class Name   {

    /**
     * A prefix to the party name. Also known as title.
     */
    @JsonProperty("prefix")
    @Size(max = 140, message = "INVALID_STRING_MAX_LENGTH")
    private String prefix = null;

    /**
     * The given name of the party. Also known as first name or name. Required if the party name is for a person.
     */
    @JsonProperty("given_name")
    @Size(max = 140, message = "INVALID_STRING_MAX_LENGTH")
    private String givenName = null;

    /**
     * The surname or family name of the party. Also known as last name. Required if the party name is for a person. Can also be used to store multiple surnames including the matronymic, or mother&#39;s, surname.
     */
    @JsonProperty("surname")
    @Size(max = 140, message = "INVALID_STRING_MAX_LENGTH")
    private String surname = null;

    /**
     * The middle name of the party. Can also be used to store multiple middle names including the patronymic name.
     */
    @JsonProperty("middle_name")
    @Size(max = 140, message = "INVALID_STRING_MAX_LENGTH")
    private String middleName = null;

    /**
     * The name suffix of the party.
     */
    @JsonProperty("suffix")
    @Size(max = 140, message = "INVALID_STRING_MAX_LENGTH")
    private String suffix = null;

    /**
     * The alternate name for the party. Can be a business name, nickname, or any other name that cannot be split into first, last name. Required for a business party name.
     */
    @JsonProperty("alternate_full_name")
    @Size(max = 300, message = "INVALID_STRING_MAX_LENGTH")
    private String alternateFullName = null;

    //region Getters & Setters
    public String getPrefix() {
        return prefix;
    }
    public void setPrefix(String prefix) {
        this.prefix = prefix;
    }

    public String getGivenName() {
        return givenName;
    }
    public void setGivenName(String givenName) {
        this.givenName = givenName;
    }

    public String getSurname() {
        return surname;
    }
    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getMiddleName() {
        return middleName;
    }
    public void setMiddleName(String middleName) {
        this.middleName = middleName;
    }

    public String getSuffix() {
        return suffix;
    }
    public void setSuffix(String suffix) {
        this.suffix = suffix;
    }

    public String getAlternateFullName() {
        return alternateFullName;
    }
    public void setAlternateFullName(String alternateFullName) {
        this.alternateFullName = alternateFullName;
    }


    //endregion


    //region Utilities

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        Name
        name = (Name) o;
            return Objects.equals(prefix, name.prefix) &&
        Objects.equals(givenName, name.givenName) &&
        Objects.equals(surname, name.surname) &&
        Objects.equals(middleName, name.middleName) &&
        Objects.equals(suffix, name.suffix) &&
        Objects.equals(alternateFullName, name.alternateFullName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(prefix, givenName, surname, middleName, suffix, alternateFullName);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("class Name {\n");
        
        sb.append("    prefix: ").append(toIndentedString(prefix)).append("\n");
        sb.append("    givenName: ").append(toIndentedString(givenName)).append("\n");
        sb.append("    surname: ").append(toIndentedString(surname)).append("\n");
        sb.append("    middleName: ").append(toIndentedString(middleName)).append("\n");
        sb.append("    suffix: ").append(toIndentedString(suffix)).append("\n");
        sb.append("    alternateFullName: ").append(toIndentedString(alternateFullName)).append("\n");
        sb.append("}");
        return sb.toString();
    }

    /**
    * Convert the given object to string with each line indented by 4 spaces
    * (except the first line).
    */
    private String toIndentedString(Object o) {
        if (o == null) {
            return "null";
        }
        return o.toString().replace("\n", "\n    ");
    }
}
